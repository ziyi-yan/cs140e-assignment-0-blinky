# CS140e assignment 0: blinky

Solution of the assignent 0 of [CS140e](https://cs140e.sergio.bz/syllabus/).

## Environment

Hardware: Raspberry Pi 3B+

Rust toolchain:

```
$ rustc --version
rustc 1.43.0-nightly (96bb8b31c 2020-03-05)
$ xargo --version
xargo 0.3.19
cargo 1.43.0-nightly (bda50510d 2020-03-02)
```

## Use latest `start.elf` for Raspberry Pi 3B+

Because the courseware is based on Raspberry Pi 3B, if you use the `start.elf` from the skeleton code, your Pi will fail on loading it.
Download the latest `start.elf` from [here](https://github.com/raspberrypi/firmware/tree/master/boot).

## Problems about breaking changes in Rust

Due to some breaking changes in Rust, the skeleton code from the course site need to be modified.

1. Delete `extern crate compiler_builtins;` because it has been [included in `#![no_std]`](https://users.rust-lang.org/t/psa-breaking-change-extern-crate-compiler-builtins-is-now-included-in-no-std-crates/16704).
2. Use stable `panic_handler` to [define panicking behavior](https://doc.rust-lang.org/nomicon/panic-handler.html) instead of `panic_fmt`.

## References

- Discussion on Raspberry Pi 3B+ problem in Reddit: https://www.reddit.com/r/cs140e/comments/8rbmjk/can_i_use_raspberry_pi_3b_to_replace_the_3b/
- `panic_fmt` language item removed in favor of `#[panic_implementation]`: https://users.rust-lang.org/t/psa-breaking-change-panic-fmt-language-item-removed-in-favor-of-panic-implementation/17875
- `panic_implementation` renamed to `panic_handler`: https://github.com/rust-lang/rust/issues/44489#issuecomment-415140224
