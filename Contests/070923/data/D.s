(require (lib "etc.ss"))
(require (lib "list.ss"))
(require (lib "math.ss"))
(define (memo4 f)
  (let ((tbl (make-hash-table 'equal)))
    (lambda (a b c d)
      (hash-table-get
       tbl
       (list a b c d)
       (lambda ()
         (let ((val (f a b c d)))
           (begin
             (hash-table-put! tbl (list a b c d) val)
             val)))))))
(define (memo3 f)
  (let ((tbl (make-hash-table 'equal)))
    (lambda (a b c)
      (hash-table-get
       tbl
       (list a b c)
       (lambda ()
         (let ((val (f a b c)))
           (begin
             (hash-table-put! tbl (list a b c) val)
             val)))))))
(define (memo2 f)
  (let ((tbl (make-hash-table 'equal)))
    (lambda (a b)
      (hash-table-get
       tbl
       (list a b)
       (lambda ()
         (let ((val (f a b)))
           (begin
             (hash-table-put! tbl (list a b) val)
             val)))))))
(define (memo1 f)
  (let ((tbl (make-hash-table 'equal)))
    (lambda (a)
      (hash-table-get
       tbl
       a
       (lambda ()
         (let ((val (f a)))
           (begin
             (hash-table-put! tbl a val)
             val)))))))
(define (get matrix s t)
  (vector-ref (vector-ref matrix t) s))
(define (put! matrix s t d)
  (cond
    ((< d (get matrix s t))
     (begin
       (vector-set! (vector-ref matrix t) s d)
       (vector-set! (vector-ref matrix s) t d)
       ))
    (#t ())))
(define (range a b)
  (cond ((> a b) '())
        (#t (cons a (range (+ a 1) b)))))
(define (for from to f)
  (map f (range from to)))
(define (read-roads n m)
  (let
      ((dist 
        (build-vector (+ n 2)
                      (lambda (i)
                        (build-vector (+ n 2) (lambda (i) 1e99))))))
    (begin
      (for 0 (+ n 1) (lambda (i) (put! dist i i 0)))
      (for 1 m (lambda (i) (begin
                             (let ((s (read))
                                   (t (read))
                                   (d (read)))
                               (put! dist s t d)))))
      dist)))
(define (floyd-warshall matrix size)
  (for 0 (- size 1) (lambda (i)
                      (for 0 (- size 1) (lambda (j)
                                          (for 0 (- size 1) (lambda (k)
       (put! matrix j k (+ (get matrix j i) (get matrix i k)))
                                                              )))))))
(define (cars n)
  (cond ((> n 10) 3)
        ((> n 5) 2)
        (#t 1)))
(define (flatten l)
  (cond ((null? (rest l)) (first l))
        (#t (append (first l) (flatten (rest l))))))
(define (cross l1 l2)
  (flatten (map (lambda (e1)
                  (map (lambda (e2) (cons e1 e2)) l2)) l1)))
(define (flatmap l f) (flatten (map l f)))
(define (counts-help cars)
  (cond ((= 0 cars) '(()))
        (#t
         (flatmap (lambda (l)
                    (let ((start (if (empty? l) 1 (car l))))
                      (map (lambda (first)
                             (cons first l))
                           (range start 5))))
                  (counts-help (- cars 1))))))
(define (counts n)
   (filter (lambda (l) (= n (sum l))) (counts-help (cars n))))
(define (sum l)
  (cond ((empty? l) 0)
        (#t (+ (car l) (sum (cdr l))))))
(define (choose l n)
  (cond ((= n 0) '(()))
        ((empty? l) '())
        (#t
         (append (choose (cdr l) n)
                 (map (lambda (c) (cons (car l) c))
                      (choose (cdr l) (- n 1)))))))
(define choose-mem (memo2 choose))
(define (contains list e)
  (cond ((empty? list) #f)
        ((= (car list) e) #t)
        (#t (contains (cdr list) e))))
(define (rem list to-rem)
  (filter
   (lambda (e) (not (contains to-rem e))) list))
(define (assignments-help counts people)
  (cond ((empty? counts) '(()))
        (#t (flatmap 
             (lambda (first-car)
               (map
                (lambda (rest) (cons first-car rest))
                (assignments-help (cdr counts) (rem people first-car))))
             (choose-mem people (car counts))))))
(define (assignments n)
  (flatmap
   (lambda (counts)
     (assignments-help counts (range 1 n)))
     (counts n)))

(define (insertions e l)
  (cond ((empty? l) (list (list e)))
        (#t
         (cons (cons e l)
               (map
                (lambda (rest) (cons (car l) rest))
                (insertions e (cdr l)))))))
(define (perms l)
  (cond ((empty? l) (list l))
        (#t 
         (flatmap
          (lambda (rest) (insertions (car l) rest))
          (perms (cdr l))))))
(define (trip-length start places end matrix)
  (if (empty? places) (get matrix start end)
      (+
       5
       (trip-length (car places) (cdr places) end matrix)
       (get matrix start (car places)))))

(define insertions-memo (memo2 insertions))
(define (f-list f l)
  (if (empty? (cdr l))
      (car l)
      (f (car l) (f-list f (cdr l)))))
(define (min-list l) (f-list min l))
(define (max-list l) (f-list max l))

(define (opt-all-assignments n matrix)
  (let ((optimal-length (lambda (places)
        (min-list (map
                   (lambda (order)
                     (trip-length 0 order (+ n 1) matrix))
                   (perms places))))))
    (let ((optimal-length-memo (memo1 optimal-length)))
      (let ((opt-all-cars (lambda (place-sets)
            (max-list (map
                       (lambda (places)
                         (optimal-length-memo places))
                       place-sets)))))  
        (min-list (map
                   (lambda (assignment)
                     (opt-all-cars assignment))
                   (assignments n)))))))

(let ((n (read))
      (m (read)))
  (let ((matrix (read-roads n m)))
    (begin
     (floyd-warshall matrix (+ n 2))
     (display (opt-all-assignments n matrix))
     (newline)
     )
    )
  )