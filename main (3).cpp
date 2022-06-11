#include <iostream>
#include <chrono>
#include <thread>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <vector>
#include <algorithm>

using json = nlohmann::json;
using std::string;
using std::cout;


struct currencyInfo
{
    string charCode_;
    std::vector<double> stats_;
};


size_t request ( char* in, size_t size, size_t num, std::string& str)
{
    size_t newLen = size * num;
    str.append(in, newLen);
    return newLen;
}


bool exitChecker = false;
std::vector<currencyInfo> in;


double mean(std::vector<double> stats)
{
    double sum = 0;
    double quantity = 0;
    for(double stat : stats)
    {
        sum += stat;
        quantity++;
    }
    return sum / quantity;
}


double median( std::vector<double> stats)
{
    std::sort(stats.begin(), stats.end());
    if (stats.size() % 2 == 1)
        return stats[stats.size() / 2];
    else
        return 0.5 * (stats[stats.size() / 2 - 1] + stats[stats.size() / 2]);
}


void stonks( std::vector<double>& stats)
{
    if(stats[stats.size() - 2] < stats[stats.size() - 1])
        cout << " \x1B[31m ▲ \033[0m\n";
    else if(stats[stats.size() - 2] > stats[stats.size() - 1])
        cout << " \x1B[32m ▼ \033[0m\n";
    else
        cout << " \x1B[33m = \033[0m\n";
}


void print( int period)
{
    int count = 1;
    while(true)
    {
        if (exitChecker)
            break;

        CURL *curl;
        curl = curl_easy_init();
        if (curl != nullptr)
        {
            curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
            string data;
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, request);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
            if (CURLE_OK == curl_easy_perform(curl))
            {
                json j = json::parse(data);
                for (const nlohmann::json &i: j["Valute"])
                {
                    int index = -1;
                    for(int k = 0; k < in.size(); k++)
                    {
                        if(in[k].charCode_ == i["CharCode"])
                        {
                            index = k;
                            in[k].stats_.emplace_back(i["Value"].get<double>() / i["Nominal"].get<double>());
                            break;
                        }
                    }
                    if(index == -1)
                    {
                        currencyInfo tmp;
                        tmp.charCode_ = i["CharCode"].get<string>();            ///???
                        tmp.stats_.emplace_back(i["Previous"].get<double>() / i["Nominal"].get<double>());
                        tmp.stats_.emplace_back(i["Value"].get<double>() / i["Nominal"].get<double>());
                        in.emplace_back(tmp);
                    }
                }
            }
            cout << "==========================[промежуточный вывод " << count++ <<"]==========================\n";
            for(auto & i : in)
            {
                cout << i.charCode_ << ":   " << i.stats_[i.stats_.size()-1];
                stonks(i.stats_);
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(period));
    }
}


void inputCheck()
{
    setlocale(LC_ALL, "RUSSIAN");
    while(getchar() != '\n'){}
    exitChecker = true;
    cout << "==========================[вывод]==========================\n";
    for (const auto& el : in)
        cout << el.charCode_ << ":  Среднее арифметическое - " << mean(el.stats_) << ", Медиана - " << median(el.stats_) << '\n';
    cout << "===========================================================\n";
    exit(0);

}


int main()
{
    int period;
    std::cin >> period;
    fflush(stdin);
    std::thread t1(inputCheck);
    t1.detach();

    print(period);

    return 0;
}