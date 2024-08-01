fn main() {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).expect("");
    let n:i32 = n.trim().parse().expect("");
    print!("Hello CMS");
    prnt(n);
}

fn prnt(n:i32) {
    if n > 0
    {
        print!("!");
        prnt(n-1);
    }
}