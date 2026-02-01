class RideSharingSystem {
private:
    queue<int> drivers;
    list<int> riders;
    unordered_map<int, list<int>::iterator> riderMap;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push_back(riderId);
        riderMap[riderId] = prev(riders.end());
    }

    void addDriver(int driverId) { drivers.push(driverId); }

    vector<int> matchDriverWithRider() {
        if (drivers.empty() || riders.empty()) {
            return {-1, -1};
        }
        int driverId = drivers.front();
        int riderId = riders.front();

        drivers.pop();
        riders.pop_front();
        riderMap.erase(riderId);

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        if (riderMap.find(riderId) != riderMap.end()) {
            auto it = riderMap[riderId];
            riders.erase(it);

            riderMap.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
