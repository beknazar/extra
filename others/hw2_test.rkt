#lang racket

(require racket/include)
(include "hw2.rkt")


(my-loop  0  10  3) ; FOR TESTING PURPOSES


(my-eval '[+  [-  3  [/ 40 [* 10 2]]]  2]) ; FOR TESTING PURPOSES