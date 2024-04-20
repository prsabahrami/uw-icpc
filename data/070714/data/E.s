(require (lib "etc.ss"))
(require (lib "math.ss"))
(require (lib "list.ss")) ; HtDP functions
(require (lib "48.ss" "srfi")) ; decimal formatting

(define (sqarea pts angle)
  (let* ((rotpts (map (lambda (x) (* angle x)) pts))
         (xvals (map real-part rotpts))
         (yvals (map imag-part rotpts)))
    (sqr (max (- (apply max xvals) (apply min xvals))
              (- (apply max yvals) (apply min yvals))))))

(define (search pts phase angle inc i bestang ans)
  (cond
    [(= phase 5)
       (format (current-output-port) "~0,2F~%" ans)]
    [(= i 1000)
       (search pts (add1 phase) (/ bestang (sqrt inc)) (expt inc 1/500) 0 bestang ans)]
    [else
       (let* ((area (sqarea pts angle)))
         (if (< area ans)
             (search pts phase (* angle inc) inc (add1 i) angle area)
             (search pts phase (* angle inc) inc (add1 i) bestang ans)))]))

(define (readpoints n)
  (if (zero? n)
      empty 
      (cons (make-rectangular (read) (read)) (readpoints (sub1 n)))))

(define (docases n)
  (if (zero? n)
      (void)
      (begin (search (readpoints (read)) 0 1 (exp (* +i pi 1/500)) 0 0 100000000)
             (docases (sub1 n)))))

(docases (read))
