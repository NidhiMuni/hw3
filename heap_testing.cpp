#include <iostream>
#include <fstream>
#include <functional>
#include "heap.h"
using namespace std;

int main(int argc, char* argv[])
{

  std::greater<int> comparator;
	Heap<int> heap(12);

  heap.push(451);
heap.push(188);
heap.push(279);
heap.push(57);
heap.push(328);
heap.push(388);
heap.push(417);
heap.push(324);
heap.push(100);
heap.push(239);
heap.push(63);
heap.push(161);
heap.push(386);
heap.push(135);
heap.push(216);
heap.push(156);
heap.push(193);
heap.push(334);
heap.push(392);
heap.push(346);
heap.push(393);
heap.push(221);
heap.push(81);
heap.push(106);
heap.push(57);
heap.push(431);
heap.push(166);
heap.push(407);
heap.push(301);
heap.push(307);
heap.push(439);
heap.push(80);
heap.push(308);
heap.push(330);
heap.push(212);
heap.push(27);
heap.push(479);
heap.push(332);
heap.push(427);
heap.push(331);
heap.push(387);
heap.push(16);
heap.push(438);
heap.push(313);
heap.push(39);
heap.push(268);
heap.push(16);
heap.push(85);
heap.push(353);
heap.push(88);
 
ap.print();

  /*for (int i = 1; i <= 50; i++){
    heap.push(i);
  }*/
  for (int i = 1; i <= 3; i++){
    heap.pop();
 
    heap.print(); }
  he	/*heap.push(1);
	heap.push(2);
	heap.push(3);
  heap.push(4);
	heap.push(5);
	heap.push(6);
  heap.push(7);
	heap.push(8);
	heap.push(9);
  heap.push(10);
	heap.push(11);
	heap.push(12);

  heap.print();*/
}