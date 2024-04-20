;; solution to contest 

(require (lib "etc.ss"))
(require (lib "list.ss"))

(define userid-table #f)
(define project-table #f)

(define (all-test-cases)
  (let ((proj (read-line)))
    (cond
      [(end-of-cases? proj) (void)]
      [else (initialize-tables)
            (initialize-project proj)
            (process-case proj)
            (all-test-cases)])))

(define (initialize-tables)
  (set! project-table (make-hash-table 'equal))
  (set! userid-table (make-hash-table 'equal)))

(define (initialize-project proj)
  (hash-table-put! project-table proj empty))

(define (end-of-cases? line)
  (equal? (substring line 0 1) "0"))

(define (process-case proj)
  (let ((next-line (read-line)))
    (cond
      [(end-of-case? next-line)
         (summarize-case)
         (void)]
      [(project? next-line)
         (initialize-project next-line)
         (process-case next-line)]
      [else
         (process-userid next-line proj)
         (process-case proj)])))

(define (end-of-case? line)
  (equal? (substring line 0 1) "1"))

(define (project? line)
  (char-upper-case? (first (string->list line))))

(define (process-userid id proj)
  (let ((lookup (hash-table-get userid-table id #f)))
    (cond
      [(number? lookup) (void)] ; disqualified
      [(not lookup) ; new student
         (hash-table-put! userid-table id proj)
         (add-to-project-table proj id)]
      [(equal? lookup proj) (void)] ; keener, already there
      [else ; disqualify
         (hash-table-put! userid-table id 0)
         (remove-from-project-table lookup id)])))

(define (add-to-project-table proj id)
  ; (printf "adding ~a to ~a\n" id proj)
  (hash-table-put! project-table proj (cons id (hash-table-get project-table proj))))

(define (remove-from-project-table proj id)
  ; (printf "removing ~a from ~a\n" id proj)
  (hash-table-put! project-table proj (remove id (hash-table-get project-table proj))))

(define (summarize-case)
  (print-list
   (sort 
    (hash-table-map project-table
                    (lambda (key val)
                      (list key (length val))))
    (lambda (pair1 pair2)
      (cond
        [(> (second pair1) (second pair2)) true]
        [(< (second pair1) (second pair2)) false]
        [else (string<? (first pair1) (first pair2))])))))

(define (print-list lst)
  (cond
    [(empty? lst) (void)]
    [else 
     (printf "~a ~a\n" (first (first lst)) (second (first lst)))
     (print-list (rest lst))]))

(all-test-cases)
    

         