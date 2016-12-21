#lang scheme

((lambda (x) (+ x 6))7)

(define (crap) "welp")
;(define crap (lambda () "welp"))


(define crap2 "welp")

(define fnc (lambda (x) (+ x 7)))
;(define (fnc x) (+ x 7))
(fnc 5)
 
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

;(define goob '(open-input-file "a.rkt"))
;(read goob)
;(define goobreader (eval goob))
;(read goobreader)

;(let ([h (car y)])
;    ))

(define hello3
  (case-lambda
    [() "hello world"]
    [(name) (string-append "hello " name)]
    [(x . y) (+ x (car y))]))
;(define (tooo . l) (let ((car l) ) (+ x too)))
(define (square x) (* x x))
(define (mean y) (/ (apply + y) (length y)))
(define (sigma  . y) 
  (sqrt(-(mean (map square y)) (square(mean y)))))
  