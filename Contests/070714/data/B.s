(define make-opthing (lambda (v x0 x1 f)
    (if (eq? x0 (- x1 1))
      (cons (cons (cons x0 x1) (vector-ref v x0)) '(() ()))
      (letrec (
          (c (floor (/ (+ x0 x1) 2)))
          (lhs (make-opthing v x0 c f))
          (rhs (make-opthing v c x1 f)))
        (cons (cons (cons x0 x1) (f (cdar lhs) (cdar rhs))) (cons lhs rhs))))))

(define get-opthing (lambda (opt x0 x1 f dfl)
    (if (eq? opt '()) dfl
      (let (
          (hx0 (caaar opt))
          (hx1 (cdaar opt))
          (val (cdar opt))
          (lhs (cadr opt))
          (rhs (cddr opt)))
        (if (or (>= x0 hx1) (>= hx0 x1)) dfl
          (if (and (>= hx0 x0) (<= hx1 x1)) val
            (f (get-opthing lhs x0 x1 f dfl) (get-opthing rhs x0 x1 f dfl))))))))

(define read-input (lambda (v i n w)
    (if (eq? i n) #f
      (begin
        (vector-set! v i (read))
        (vector-set! w (vector-ref v i) i)
        (read-input v (+ i 1) n w)))))

(define doit2 (lambda (minthing min mindfl maxthing max maxdfl x0 x1 pos)
    (if (>= x0 x1) 0
      (begin
        (letrec (
            (x2 (vector-ref pos (get-opthing maxthing x0 x1 max maxdfl)))
            (left (doit2 minthing min mindfl maxthing max maxdfl x0 x2 pos))
            (right (doit2 maxthing max maxdfl minthing min mindfl
                            (+ x2 1) x1 pos)))
          (+ (* (floor (/ left 2)) 2) 1 right))))))


(define doit (lambda (n)
    (let (
        (v (make-vector n))
        (w (make-vector (+ n 1))))
      (begin
        (read-input v 0 n w)
        (let (
            (maxthing (make-opthing v 0 n max))
            (minthing (make-opthing v 0 n min)))
          (begin
            (display (doit2 minthing min 77777 maxthing max -1 0 n w))
            (newline)))))))

(define main (lambda (n)
    (if (eq? n 0) #f
      (begin
        (doit (read))
        (main (- n 1))))))

(main (read))
