<div align="center">

# 🔁 push_swap

**Sort a stack of integers using a tiny instruction set — and as few moves as possible.**

![Language](https://img.shields.io/badge/language-C-00599C?style=flat-square)
![42](https://img.shields.io/badge/42-Common%20Core-000000?style=flat-square)
![Topic](https://img.shields.io/badge/algorithms-%2B%20complexity-8A2BE2?style=flat-square)
![Norminette](https://img.shields.io/badge/norm-42%20standard-2b9348?style=flat-square)
![Stars](https://img.shields.io/github/stars/ifrankerem/Push_Swap?style=flat-square)

</div>

---

## 📋 Table of Contents

- [About](#about)
- [The Instruction Set](#the-instruction-set)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Benchmarks](#benchmarks)
- [Project Layout](#project-layout)
- [Design Notes](#design-notes)
- [Demo](#demo)
- [Author](#author)

---

## 📖 About

**push_swap** takes two stacks — `a` (holding a shuffled list of integers) and
an empty `b` — and prints the shortest sequence of stack operations that
leaves `a` sorted in ascending order.

It's the 42 project that turns data-structure manipulation into an optimisation
problem: the grading is not "is it sorted" but "how many moves did it cost".

---

## 🔧 The Instruction Set

| Operation | Effect |
|---|---|
| `sa` | swap the top two of `a` |
| `sb` | swap the top two of `b` |
| `ss` | `sa` and `sb` together |
| `pa` | push the top of `b` onto `a` |
| `pb` | push the top of `a` onto `b` |
| `ra` | rotate `a` up (first becomes last) |
| `rb` | rotate `b` up |
| `rr` | `ra` and `rb` together |
| `rra` | reverse rotate `a` |
| `rrb` | reverse rotate `b` |
| `rrr` | `rra` and `rrb` together |

---

## 🚀 Getting Started

**Prerequisites**

- `gcc` or `clang`
- `make`

**Build**

```sh
git clone https://github.com/ifrankerem/Push_Swap.git
cd Push_Swap
make
```

---

## 💻 Usage

```sh
ARG="4 67 3 87 23"
./push_swap $ARG          # prints the operation list
./push_swap $ARG | ./checker_OS $ARG     # prints OK or KO
```

Invalid input prints `Error`:

```sh
$ ./push_swap 0 one 2 3
Error
```

---

## 🧠 Algorithm

The move count is what's being optimised, so the strategy branches on input
size:

- **Small stacks** — insertion sort and hardcoded optimal sequences for 3 and
  5 elements.
- **Large stacks** — index normalisation then a chunked or radix-style sort over
  the normalised values, using least moves to place each element.

Chunks are chosen so every candidate moves the same distance, which is what
keeps the move count near the theoretical floor instead of exploding with
input size.

---

## 📊 Benchmarks

| Input size | Full marks | Passing threshold |
|---|---|---|
| 100 numbers | < 700 moves | < 1100 moves |
| 500 numbers | < 5500 moves | < 8500 moves |

---

## 🗂 Project Layout

```
Push_Swap/
├── main.c / parsing.c / error.c     # argument handling and validation
├── algo.c / algo2.c                # strategy selection and sorting
├── pushmoves.c / swapmoves.c        # push and swap operations
├── rotatemoves.c / reversorotatemoves.c
├── stack_utils.c / stack_utils2.c   # stack helpers
├── utils.c
├── libft/
└── assets/                          # visualisation
```

---

## 🧠 Design Notes

- Arguments are validated for syntax, duplicates and `int` range before any
  allocation.
- Values are normalised to `0..n-1` so comparison-based logic doesn't care
  about magnitude, only rank.
- Cost is computed as rotation distance plus insertion cost, which is what the
  move-minimiser actually optimises.
- Built with the 42 flags, `-Wall -Wextra -Werror`, Norminette-clean.

---

## 🎥 Demo

▶️ [Watch on YouTube](https://www.youtube.com/watch?v=rY4tZnFEBo8)

---

## 👤 Author

**İrfan Kerem Arslan** — [@ifrankerem](https://github.com/ifrankerem)

---

## 📄 License

Built for the **42 Common Core** curriculum. Shared for learning and portfolio
purposes.

---

## 🙏 Acknowledgements

- [awesome-readme](https://github.com/matiassingers/awesome-readme) — structure inspiration for this README