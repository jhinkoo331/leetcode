
/**
 * @perf: 92, 100
 * @time: linear
 * @space: constant
 */
int _1(int* gas, int gasSize, int* cost, int costSize);

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
        return _1(gas, gasSize, cost, costSize);
}


int _1(int* gas, int gasSize, int* cost, int costSize){
        if(gasSize == 1)
                return gas[0] >= cost[0] ? 0 : -1;
        for(int i = 0; i < gasSize; ++i)
                gas[i] -= cost[i];
        int min_gas = gas[0];
        int min_index = 0;
        int sum = min_gas;
        for(int i = 1; i < gasSize; ++i){
                sum += gas[i];
                if(sum < min_gas){
                        min_gas = sum;
                        min_index = i;
                }
        }
        if(sum < 0)
                return -1;
        else
                return (min_index + 1) % gasSize;
}
