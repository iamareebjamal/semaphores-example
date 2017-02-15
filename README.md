# Dining Philosophers using Semaphores  
[![Codacy grade](https://img.shields.io/codacy/grade/e05f34ee709541de8446efca8cf15f0e.svg)]()
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)  

> Basic process synchronisation using semaphores in linux demonstrated by special kind of Dining Philosophers problem

Project used POSIX semaphores to synchronise chopsticks among 6 philosophers sitting across a table.

See [this](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

### Description

This repo contains a special form of this problem.

- There are only 3 chopsticks shared among the philosophers
- There are 4 chopsticks on the table
- First, the philospher has to pick up a chopstick from his side (from the 3 fixed ones)
- Then, he has to pick one from the 4 kept on table. There is no resourse hierarchy among these, nor any absolute posiition.
- Eat! Profit

### *classic* branch

The `classic` branch contains the solution to the original classic problem

### Author

Areeb Jamal - [@iamareebjamal](https://github.com/iamareebjamal)
