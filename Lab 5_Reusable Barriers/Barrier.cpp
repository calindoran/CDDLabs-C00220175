// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Calin Doran
// Maintainer: 
// Created:
// Version: 
// Package-Requires:
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.

// Code:
#include "Barrier.h"
#include "Semaphore.h"
#include <iostream>

/*!
@fn Barrier(int Threads)

@brief Barrier constructor with one  parameter of type int 
@param Threads
@return none
*/


Barrier::Barrier(int Threads)
{
    this->Threads = Threads;
    Count = 0;
    mutex.reset(new Semaphore(1));
    Task_One.reset(new Semaphore(0));
    Task_Two.reset(new Semaphore(1));
}

/*!
@fn ~Barrier()
@brief virtual Barrier constructor used to reset all semaphores
@param none
@return none
*/

Barrier::~Barrier(){
    mutex.reset();
    Task_One.reset();
    Task_Two.reset();
}

/*!
@fn phase_one
@brief phase one contains the implementation of the first turnstile
@param none
@return none
*/

void Barrier::phase_one(){
    mutex->Wait();
    ++Count;
    if (Count == Threads)
    {
        Task_Two->Wait();
        Task_One->Signal();
    }
    mutex->Signal();
    Task_One->Wait();
    Task_One->Signal();
}

/*!
@fn phase_two
@brief phase two contains the implementation of the secons turnstile
@param none
@return none
*/

void Barrier::phase_two(){
    mutex->Wait();
    --Count;
    if (Count == 0)
    {
        Task_One->Wait();
        Task_Two->Signal();
    }
    mutex->Signal();
    Task_Two->Wait();
    Task_Two->Signal();
}

// 
// Barrier.cpp ends here
