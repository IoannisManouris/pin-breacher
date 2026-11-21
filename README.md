# Pin Breacher

A small C++ console game that guesses a sample PIN entered by the player. Every guess is compared with the value in memory. All input and output stay in the terminal.

## Purpose and audience

For someone learning C++, the printed guesses make random sampling and duplicate detection easy to follow. Try one digit, then two, to see how the search space grows.

## How it works

The program generates strings of the same length as the sample, keeps distinct guesses in a vector and prints the number tried when it finds a match. Leading zeros count. The demo accepts one to four digits and offers a replay after each round. Duplicate checks scan the vector, so a four-digit example can take a while and print thousands of lines.

## Quick start and commands

Build with a C++17 compiler from the repository root. The only dependency is the C++ standard library.

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic breacher.cpp -o build/pin-breacher
./build/pin-breacher
```

Enter `07` at the prompt. When the program finds it, it prints the number of distinct attempts. Enter `N` to finish. On Windows with MinGW, use `build/pin-breacher.exe` as the output and run that file.

## Configuration and testing

No external service or configuration file is required. After building, this shell command exercises input validation and a complete round.

```bash
printf 'abc\n7\nN\n' | ./build/pin-breacher
```

Expect a validation prompt for `abc`, a success message for `7` and a clean exit. CI compiles the source and checks those outputs.

## Troubleshooting

Use a one- or two-digit sample for a short session. A terminal that supports ANSI escape codes displays the matching guess in green.

## History and release status

The local source file has a creation timestamp of October 11, 2024. GitHub records the repository creation and the [original source commit](https://github.com/IoannisManouris/pin-breacher/commit/16d658e29e79f4edf02d5a5e6e04f0ad5724070c) on November 14, 2025. No historical tag or GitHub Release was found.

## Support and security

Open a repository issue for a reproducible bug. Report security concerns privately using [SECURITY.md](SECURITY.md). See the [license notice](LICENSE) for reuse terms.
