#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <map>

class Prison{
    public:
        Prison(int total){
            for(int i=0; i<total;i++){
                nums1.push_back(i);
                nums2.push_back(i);
            }
            fillPrisoners(total);
            fillDoors(total);
        }

        void fillPrisoners(int total){
            srand (time(NULL));
            int size=total, index=0;
            while(size>=1){
                int pos=rand()%size;
                int num=nums1[pos];
                nums1.erase(nums1.begin()+pos);
                prisoners[index]=num;
                size--;
                index++;
            }
        }
    
        void fillDoors(int total){
            srand (time(NULL));
            int size=total, index=0;
            while(size>=1){
                int pos=rand()%size;
                int num=nums2[pos];
                nums2.erase(nums2.begin()+pos);
                doors[index]=num;
                size--;
                index++;
            }
        }

        bool search(int prisoner_num, int total){
            int index=0, cur=prisoner_num;
            while(index<total/2){
                 cur=doors[cur];
                if(cur==prisoner_num)
                    return true;
                else{
                    index++;
                }
            }
            return false;
        }

        bool all_prisoners(int total){
            for(int i=0; i<total; i++){
                bool found=search(i, total);
                if(!found)
                    return false;
            }
            return true;
        }

    private:
        std::vector<int>nums1;
        std::vector<int>nums2;
        std::map<int, int>prisoners;
        std::map<int,int>doors;
};

int main(){
        Prison p(100);
        std::cout << p.all_prisoners(100)<<std::endl;
    
}
