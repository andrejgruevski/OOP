//
// Created by Huhe on 5/13/2025.
//
#include "iostream"
#include "cstring"
using namespace std;
class Weather {
protected:
    double temp;
public:
    Weather(double temp=0){
        this->temp=temp;
    }
    virtual bool isDangeours() const = 0;
    virtual void displayWeatherInfo() const =0;
};
class SunnyWeather:public Weather{
private:
    double uv;
public:
    SunnyWeather(double temp = 0,double uv = 0): Weather(temp){
        this->uv=uv;
    }
    bool isDangeours() const override{
        if (uv > 8 ){
            return true;
        }
        return false;
    }
    void displayWeatherInfo() const override{
//        The weather is sunny, temperature: [temperature]°C, UV index: [uv]
        cout<<"The weather is sunny, temperature: "<<temp<<"°C, UV index: "<<uv;
        if (isDangeours()){
            cout<<", not recommended to go out";
        }
    }
};
class RainyWeather:public Weather{
private:
    double mm;
    bool isStorm;
public:
    RainyWeather(double temp=0, double mm = 0, bool isStorm= false): Weather(temp){
        this->mm=mm;
        this->isStorm=isStorm;
    }
    bool isDangeours() const override{
        if (isStorm && mm > 10){
            return true;
        }
        return false;
    }
    void displayWeatherInfo() const override{
        cout<<"The weather is rainy, temperature: "<<temp<<"°C, amount of rain: "<<mm<<"mm";
        if (isDangeours()){
            cout<<", not recommended to go out";
        }
    }
};
class WindyWeather:public Weather{
private:
    double speed;
    bool isHurricane;
public:
    WindyWeather(double temp = 0, double speed = 0, bool isHurricane = false): Weather(temp){
        this->speed=speed;
        this->isHurricane=isHurricane;
    }
    bool isDangeours()const override{
        if (isHurricane && speed>80){
            return true;
        }
        return false;
    }
    void displayWeatherInfo() const override{
        cout<<"The weather is windy, temperature: "<<temp<<"°C, wind speed: "<<speed<<"km/h";
        if (isDangeours() && isHurricane){
            cout<<", not redommended to go out, there is a hurricane";
        }
    }
};
Weather **getDangerousWeather(Weather **weathers, int n, int &dangerousCount) {
    dangerousCount = 0;
    for (int i = 0; i < n; i++) {
        if (weathers[i]->isDangeours()) {
            dangerousCount++;
        }
    }

    Weather **w = new Weather *[dangerousCount];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (weathers[i]->isDangeours()) {
            w[j++] = weathers[i];
        }
    }
    return w;
}
//Weather** displayDangerousWeather(Weather **tmp, int n, int &dangerousCount) {
//    Weather **dangerous = new Weather*[n];
//    dangerousCount = 0;
//    for (int i = 0; i < n; i++) {
//        if (tmp[i]->isDangeours()) {
//            dangerous[dangerousCount++] = tmp[i];
//        }
//    }
//    return dangerous;
//}

int main() {
    Weather *weathers[5];
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "TEST CASE 1: TESTING SUNNY WEATHER CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            double temp, uv;
            cin >> temp >> uv;
            weathers[i] = new SunnyWeather(temp, uv);
            weathers[i]->displayWeatherInfo();
        }
    } else if (testCase == 2) {
        cout << "TEST CASE 2: TESTING RAINY WEATHER CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            double temp, mm;
            bool isStorm;
            cin >> temp >> mm >> isStorm;
            weathers[i] = new RainyWeather(temp, mm, isStorm);
            weathers[i]->displayWeatherInfo();
        }
    } else if (testCase == 3) {
        cout << "TEST CASE 3: TESTING WINDY WEATHER CLASS" << endl;
        for (int i = 0; i < 5; i++) {
            double temp, speed;
            bool isHurricane;
            cin >> temp >> speed >> isHurricane;
            weathers[i] = new WindyWeather(temp, speed, isHurricane);
            weathers[i]->displayWeatherInfo();
        }
    } else if (testCase == 4) {
        cout << "TEST CASE 4: TESTING ALL CLASSES" << endl;
        for (int i = 0; i < 5; i++)