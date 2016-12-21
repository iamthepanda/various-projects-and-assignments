#lang scheme

((lambda (x) (+ x 6))7)
 
(define (fnc x) (+ x 7))
(fnc 6)
 
(define (double1 x) (+ x x))
  		(map double1 '(1 2 3 4 5))
 
(eq? '(1) '(1))

(define (double x) (+ x x))
(eq? 10 (double 5))

(equal? 10 (double 5))

(eqv? 10 (double 5))

 
(define (func1 x y) ( y (x 3 3) 10))
(func1 / +)
  

(define (print) display "hello world")
	(define (function) (print))
(function)
  
;(define inport(open-input-file "g.rkt"))
;; hook to current namespace
;(define-namespace-anchor anc)
;(define ns (namespace-anchor->namespace anc))
;(printf "1g: reading function from file: ~a\n" (eval (read inport) ns))
;(display "\n")

;(define blob(open-input-file "g.rkt"))
;; hook to current namespace
;(define-namespace-anchor anc2)
;(define ns2 (namespace-anchor->namespace anc2))

(define goob(open-input-file "g.rkt"))
(eval(read goob))