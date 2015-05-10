#lang scheme

(define (my-loop a b c)
(let lp ((i a) (s 0))
   (if (>= i b) s (lp (+ i c) (+ s i)))
   )
)

; (my-loop  0  10  3) ; FOR TESTING PURPOSES

(define (my-eval a)
  (cond
    [(list? a) (cond
      [(eq? (car a) '+) (+ (my-eval (second a)) (my-eval (third a)))]
      [(eq? (car a) '-) (- (my-eval (second a)) (my-eval (third a)))]
      [(eq? (car a) '*) (* (my-eval (second a)) (my-eval (third a)))]
      [(eq? (car a) '/) (/ (my-eval (second a)) (my-eval (third a)))]
      )]
    [(number? a) a]
    )
  )



; (my-eval '[+  [-  3  [/ 40 [* 10 2]]]  2]) ; FOR TESTING PURPOSES

; (define (s)
;   (display ">> ")
;   (let ((a (read)))
;     (unless (eof-object? a)
;       (display (my-eval a))
;       (newline)
;       (s))))