#lang racket

#|
Lab 1:  Introduction to Racket and unit testing in Racket
CS 270 (Math Foundations of CS)

Before beginning this lab you should have installed DrRacket.  You
should also take a few minutes to review the functions in this file
so that you understand what they are supposed to do and how to run
unit tests in Racket.

Next open DrRacket and load this file (select Open in the File menu)
into DrRacket and answer the embedded questions in the definition panel
of DrRacket. After answering each question, click the Run button to
check your answer.  If you made a mistake, you should make the
appropriate changes and click the Run button again.

After you load this file into DrRacket and before you start answering
the questions, click the Run button.  You should see the following
summary from running the unit tests in insertionsort3-suite.

10 success(es) 0 failure(s) 0 error(s) 10 test(s) run
0

|#

(require racket/contract)
(require rackunit)
(require rackunit/text-ui)

; Predicate to determine if the input is a list of integers.
; Input:   L is an arbitrary Racket object.
; Output:  boolean which is true if L is a list of integers and
;          false otherwise.
; Note:  The library function list? is a predicate to detect lists.
;        A predicate to detect lists of a given type can be obtained
;        from (flat-contract-predicate integer?)
(define (intlist? L)
  (if (null? L)
      #t
      (and (pair? L) (integer? (first L)) (intlist? (rest L)))))

; A predicate to determine if a list of integers is sorted.
; Input:  L a list of integers
; Output: boolean true of L is sorted false otherwise
(define (sorted? L)
   (cond
   [(null? L) #t]
   [(equal? (length L) 1) #t]
   [else (and (<= (first L) (second L)) 
         (sorted? (rest L)))]
   ))


; A predicate to determine if one list is permutation of another
; Input:  P and L are lists of integers
; Output: boolean which is true if L is a permutation of P
;         false otherwise.
(define (permutation? P L)
  (if (null? P)
      (null? L)
      (and (member (car P) L)
           (permutation? (remove (first P) P) (remove (first P) L)))))

; A function to insert an integer into a sorted list
; Input:  (and (integer? x) (intlist? L) (sorted? L))
; Output: (let (M (insert x L))
;              (and (intlist? M) (sorted? M) (permutation? M (cons x L))))
(define (insert x L)
  (cond
   [(null? L) (list x)]
   [(<= x (first L)) (cons x L)]
   [else (cons (first L) (insert x (rest L)))]
   ))

; A function to sort a list of integers using insertion sort
; Input:  (intlist? L)
; Output: (let (M (insertionsort L))
;              (and (intlist? M) (sorted? M) (permutation? M L)))
(define (insertionsort L)
  (if (null? L)
    null
    (insert (first L) (insertionsort (cdr L)))))

; Unit tests - tests all possible lists of three elements.
(define-test-suite insertionsort3-suite
  (check-equal? 
    (insertionsort '(1 2 3)) '(1 2 3))

  (check-equal? 
    (insertionsort '(1 3 2)) '(1 2 3))

  (check-equal? 
    (insertionsort '(2 1 3)) '(1 2 3))

  (check-equal? 
    (insertionsort '(2 3 1)) '(1 2 3))

  (check-equal? 
    (insertionsort '(3 1 2)) '(1 2 3))

  (check-equal? 
    (insertionsort '(3 2 1)) '(1 2 3))

  (check-equal? 
    (insertionsort '(1 1 2)) '(1 1 2))

  (check-equal? 
    (insertionsort '(1 2 1)) '(1 1 2))

  (check-equal? 
    (insertionsort '(2 1 1)) '(1 1 2))

  (check-equal? 
    (insertionsort '(1 1 1)) '(1 1 1))
)
(run-tests insertionsort3-suite 'verbose)

; Question 1
; Unit tests - test all possible insertions into a sorted list of
; length 2.  You may assume the sorted list is (1 3) and you need
; 3 cases that cover the different possible locations where x can be
; inserted.  Create a test-suite called insert3-suite using
; define-test-suite from Racket's unit test package - follow the example
; above.  After defining the test suite, run the tests using the function
; run-tests.

(define-test-suite insert3-suite
  (check-equal?
    (insert 2 '(1 3)) '(1 2 3))

  (check-equal? 
    (insert 6 '(1 3)) '(1 3 6))

  (check-equal? 
    (insert 0 '(1 3)) '(0 1 3))
  )

(run-tests insert3-suite)


; Question 2
; Unit tests - Write unit tests to test the base cases for insert and
; insertionsort.  Call the test suite basecases-suite and make sure
; both tests pass

(define-test-suite basecases-suite
  (check-equal?
    (insertionsort '(1 3 2)) '(1 2 3))

  (check-equal? 
    (insert 6 '(1 3)) '(1 3 6))

)
(run-tests basecases-suite 'verbose)


#|
   Question 3.
   Implement a function (sort3 L) which inputs a list of three integers
   and returns a list of the same 3 numbers in sorted order.  Your
   function should inline the comparisons using (if expr then else)
   and should not use recursion.  You should use the functions first, second
   and third to access the three elements of the list L.  Use the function
   list to construct the resulting list.  Verify the correctness of your
   sort3 using the same unit test that was applied to insertionsort.
|#

; insert definition of sort3 here.  Make sure you have comments that
; informally provide the input and output specifications for sort3.

(define (sort3 L)
   ( if ( <= (first L) (second L) (third L)) (list(first L) (second L) (third L))
   ( if ( <= (third L) (second L) (first L)) (list(third L) (second L) (first L))
   ( if ( < (second L) (third L) (first L)) (list(second L) (third L) (first L))
   ( if ( < (second L) (first L) (third L)) (list(second L) (first L) (third L))
   ( if ( <= (first L) (third L) (second L)) (list(first L) (third L) (second L))
   ( if ( < (third L) (first L) (second L)) (list(third L) (first L) (second L)) null)
  ))))))

; Unit tests - tests all possible lists of three elements.
; Copy the definition of the test suite insertionsort3-suite from
; above and rename it sort3-suite.  Make sure you replace calls to
; insertionsort by calls to sort3.  Then run sort3-suite using
; (run-tests insertionsort3-suite 'verbose)
; Make sure all tests pass.  If not you will need to debug your
; implementation of sort3.

(define-test-suite sort3-suite
  (check-equal? 
    (sort3 '(1 2 3)) '(1 2 3))

  (check-equal? 
    (sort3 '(1 3 2)) '(1 2 3))

  (check-equal? 
    (sort3 '(2 1 3)) '(1 2 3))

  (check-equal? 
    (sort3 '(2 3 1)) '(1 2 3))

  (check-equal? 
    (sort3 '(3 1 2)) '(1 2 3))

  (check-equal? 
    (sort3 '(3 2 1)) '(1 2 3))

  (check-equal? 
    (sort3 '(1 1 2)) '(1 1 2))

  (check-equal? 
    (sort3 '(1 2 1)) '(1 1 2))

  (check-equal? 
    (sort3 '(2 1 1)) '(1 1 2))

  (check-equal? 
    (sort3 '(1 1 1)) '(1 1 1))
)
(run-tests sort3-suite)
