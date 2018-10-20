#lang racket

 (define (sqr x) (* x x))

(define (negative x)
  (if (< x 0) 1 0)
 )


(define (mapi f L)
  (if (null? L)
      null
      (cons (f (first L)) (mapi f (rest L)))
      )
  )

(define (reduce f init L)
  (if (equal? (length L) 1) (f (first L) init) (f (first L) (reduce f init (rest L))))
  )

(define (possible x)

  

  )

