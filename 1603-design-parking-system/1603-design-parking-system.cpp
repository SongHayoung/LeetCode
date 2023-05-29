class ParkingSystem {
    int b, m, s;
public:
    ParkingSystem(int big, int medium, int small): b(big), m(medium), s(small) {
        
    }
    
    bool addCar(int carType) {
        if(carType == 3 and s) {
            s--;
            return true;
        } else if(carType == 2 and m) {
            m--;
            return true;
        } else if(carType == 1 and b) {
            b--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */