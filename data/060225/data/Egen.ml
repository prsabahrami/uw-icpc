Random.self_init ();;

let rec repeat = fun f v n ->
    if n=0 then v
    else repeat f (f v) (n-1);;

let cases = 1000;;
print_int cases;;
print_newline ();;
repeat (fun _ ->
    let n = 1+(Random.int 10) in
    print_int n;
    print_newline ();
    repeat (fun _ ->
        print_char (Char.chr ((Random.int 26)+(Char.code 'a')));
        print_char ' ';
        print_int (Random.int 11);
        print_newline ()) () n) () cases
;;
