//Author: Calin Doran
//Program: Barrier

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;

/*! \fn barrierTask
    \brief An example of using a reusable barrier

*/

/*! shows message to split in to two parts in order to show how rendezvous work

*/

void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first part of task
    std::cout <<"A"<< i ;
    //Barrier
    theBarrier->phase_one();
  
    //Do second half of task
    std::cout<<"B"<< i ;
    theBarrier->phase_two();

  }
}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
    v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
