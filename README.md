# inference-engine-gpt2

CPU-only GPT-2 inference in C++20. Loads Hugging Face `gpt2` weights from plain text dumps, runs the full transformer stack (layer norm, multi-head causal attention, MLP/GELU, tied LM head), and samples with top-k.

## Layout

| Path          | Purpose                                                        |
|---------------|----------------------------------------------------------------|
| `inference/`  | C++ inference (`main.cc`) — planned                            |
| `modelLoader/`| Export HF GPT-2 weights + tokenizer to `weights/`             |
| `weights/`    | Parameter `.txt` dumps + GPT-2 tokenizer (gitignored, ~1.4 GB) |

## Prerequisites

- `g++` with C++20 support (for the inference step)
- Python 3.14 + [`uv`](https://docs.astral.sh/uv/) (only to export weights)

## 1. Export weights

```sh
cd modelLoader
uv sync
uv run main.py
```

This writes `../weights/transformer.*.txt` and saves the tokenizer under `weights/tokenizer/`.

No `uv`? Plain pip works too:

```sh
cd modelLoader
python -m venv .venv
source .venv/bin/activate
pip install torch transformers
python main.py
```

## 2. Build & run (planned)

`inference/` isn't implemented yet. Intended flow:

```sh
cd inference
g++ -std=c++20 -O3 -o gpt2 main.cc -I.
./gpt2
```

On start, vocab and weights load once. Then you get a loop:

- `prompt` — generation prompt (empty line quits)
- `num tokens` — how many new tokens to sample

Defaults: temperature `0.8`, top-k `40`.

## Notes

- Weight files under `weights/*.txt` are large (~1.4 GB) and ignored by git; regenerate them locally with `modelLoader/main.py`.
- `weights/tokenizer/` (small, ~3.4 MB) **is** tracked, so clones work without re-downloading the tokenizer.
- Paths in the C++ loader are relative to `inference/` (`../weights/...`).

## License

MIT — see [LICENSE](LICENSE).
