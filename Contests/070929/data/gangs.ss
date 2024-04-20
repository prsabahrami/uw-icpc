(require (lib "etc.ss"))
(require (lib "list.ss"))
(require (lib "array.ss" "srfi" "25"))
(require (lib "list.ss" "srfi" "1"))

(define n 20)
(define table (make-array (shape 1 (add1 n) 1 (add1 n)) false))
(array-set! table 1 1 1) ; base case

;; computes number of runs of length 2m with first subrun
;;  of length 2i or more (i >= 1)
;; memoizing to save time
;; don't need to know the closed-form solution (Catalan numbers)
(define (nrun m i)
  (cond
    [(number? (array-ref table m i)) (array-ref table m i)]
    [(= i m) ; only one subrun, must begin with E, end with S, rest is run
       (let ([answer (nrun (sub1 m) 1)])
         (array-set! table m i answer)
         answer)]
    [else ; add first subruns of length 2i+2 or more to first subruns of length exactly 2i
       (let ([answer (+ (nrun m (add1 i)) (* (nrun i i) (nrun (- m i) 1)))])
         (array-set! table m i answer)
         answer)]))

;; computes list of chars of ith path (0-based) of length 2m
(define (ith-path m i)
  (cond
    [(zero? m) empty]
    [(>= i (nrun m 1)) (string->list "ERROR")]
    [else (ith-path-helper m i 1)]))

;; computes list of chars of ith path of length 2m knowing
;;  length of first subrun is at least 2j (j >= 1)

(define (ith-path-helper m i j)
  (cond
    [(= j m) ; length of first subrun is 2m
     (append (list #\E) (ith-path (sub1 m) i) (list #\S))]
    [(< i (nrun m (add1 j))) ; length of first subrun is > 2j
       (ith-path-helper m i (add1 j))] ; keep going
    [else ; length of first subrun is 2j
       (let* ([i-within (- i (nrun m (add1 j)))] ; forget shorter subruns
              [rank-first (quotient i-within (nrun (- m j) 1))]
              [rank-rest (remainder i-within (nrun (- m j) 1))])
         (append (ith-path j rank-first) (ith-path (- m j) rank-rest)))]))

;; computes rank (0-based) of path given as list of chars
(define (rank pl)
  (let ([len (length pl)]
        [sublen (len-1st-subrun pl)])
    (cond
      [(= len 2) 0]
      [(= len sublen) (rank (drop (take pl (sub1 len)) 1))]
      [else
        (+ (nrun (/ len 2) (add1 (/ sublen 2)))
           (* (rank (take pl sublen))
              (nrun (/ (- len sublen) 2) 1))
           (rank (drop pl sublen)))])))

;; computes length of first subrun of pl
(define (len-1st-subrun pl)
  (len-1st-subrun-helper pl 0 0))

;; computes length of first subrun of pl given len-so-far i and sum-so-far sum
(define (len-1st-subrun-helper pl i sum)
  (cond
    [(empty? pl) i]
    [(char=? (first pl) #\E) (len-1st-subrun-helper (rest pl) (add1 i) (add1 sum))]
    [(= sum 1) (add1 i)]
    [else (len-1st-subrun-helper (rest pl) (add1 i) (sub1 sum))]))

;; grind through input format
(define (all-instances)
  (if (process-instance (sub1 (string->number (read-line))))
      (all-instances)
      (void)))

(define (process-instance n)
  (let* ([query (read-line)]
         [ql (string->list query)])
    (cond
      [(char=? #\- (first ql)) false]
      [(char=? #\0 (first ql)) true]
      [(char=? #\E (first ql)) (printf "~s\n" (add1 (rank ql))) (process-instance n)]
      [else (write-string (list->string (ith-path n (sub1 (string->number query)))))
            (newline)
            (process-instance n)])))

(all-instances)
  

