class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->b = big;
        this->m = medium;
        this->s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 3)
        {
            if(this->s == 0) return false;
            
            this->s -=1;
            return true;
        }
         if(carType == 2)
        {
            if(this->m == 0) return false;
            
            this->m -=1;
            return true;
        }
         if(carType == 1)
        {
            if(this->b == 0) return false;
            
            this->b -=1;
            return true;
        }
        return false;
    }
    int b,m,s;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */