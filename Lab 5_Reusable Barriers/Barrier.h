/* Barrier.h --- Barrier.h
 * 
 * Filename: Barrier.h
 * Description: The Barrier header file
 * Author: Calin Doran

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#pragma once
#include "Semaphore.h"

class Barrier{
private:
  int Count;
  int Threads;
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> Task_One;
  std::shared_ptr<Semaphore> Task_Two;
public:
  Barrier(int Threads);
  virtual ~Barrier();
  void wait();
  void phase_one();
  void phase_two();
};


/* Barrier.h ends here */
