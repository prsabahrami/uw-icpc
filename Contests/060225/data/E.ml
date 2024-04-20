#load "extLib.cma";;

module StringSet = Set.Make (String);;

let rec repeat = fun f v n ->
    if n=0 then v
    else repeat f (f v) (n-1);;

let input_n = fun f v -> repeat f v (read_int ());;

let puts = fun s -> print_string s; print_newline ();;

let sort_string = fun s ->
    ExtString.String.implode (List.sort Char.compare (ExtString.String.explode s));;

let dict = input_n (fun v -> StringSet.add (sort_string (read_line ())) v) StringSet.empty ;;

let in_dict = fun w -> StringSet.mem (ExtString.String.implode w) dict;;

let rec go = fun chars score str ->
    match chars with
      [] -> if in_dict str then (str, score) else (str, 0)
    | (c, i)::tl ->
        let (str1, sc1) = (go tl score str) in
        let (str2, sc2) = (go tl (score+i) (c :: str)) in
            if sc1 > sc2 then (str1, sc1)
            else (str2, sc2)
;;

let sort_hand = fun hand ->
    List.sort (fun (c, i) (c2, i2) -> Char.compare c2 c) hand;;

let read_hand = fun _ ->
    input_n (fun v -> (Scanf.scanf "%c %d\n" (fun c i -> (c, i))) :: v ) [];;

let to_string = fun (str, sc) ->
(*    (ExtString.String.implode str) ^ (string_of_int sc);; *)
    string_of_int sc;;

input_n (fun v -> puts (to_string (go (sort_hand (read_hand ())) 0 []))) ();;

