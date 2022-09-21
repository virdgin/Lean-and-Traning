#include "bus_manager.h"

using namespace std;
BusManager::BusManager()
{
    stops_ = map<string, vector<string>>();
    buses_ = map<string, vector<string>>();
}

void BusManager::AddBus(const string &bus, const vector<string> &stops)
{
    bool flag;
    buses_[bus] = stops;
    for (const auto &i : stops)
    {
        flag = true;
        for (const auto &j : stops_[i])
        {
            if (j == bus)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            stops_[i].push_back(bus);
        }
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const
{
    if (stops_.count(stop) == 0)
    {
        return {};
    }
    return {stop, stops_.at(stop)};
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const
{
    return {bus, buses_, stops_};
    ;
}

AllBusesResponse BusManager::GetAllBuses() const
{
    return {buses_};
}