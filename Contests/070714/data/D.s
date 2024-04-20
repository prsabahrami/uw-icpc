(require (lib "42.ss" "srfi")
  (lib "48.ss" "srfi")
  (lib "32.ss" "srfi"))

(define (readn n)
  (if (= n 0)
    '()
    (cons (read) (readn (sub1 n)))))

(define (doit)
  (define f (read))
  (unless (= f 0)
    (let*
      ((r (read))
       (fs (readn f))
       (rs (readn r))
       (ds
 	 (vector-ec (: n rs) (: m fs)
	   (/ n m))))
      (vector-sort! < ds)
      (let ((ans
	      (max-ec (: i (sub1 (vector-length ds)))
		(/ (vector-ref ds (add1 i)) (vector-ref ds i)))))
	(format (current-output-port) "~0,2F~%" ans)
	(doit)))))
(doit)
