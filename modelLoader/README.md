# modelLoader

Exports Hugging Face `gpt2` weights + tokenizer into plain text files under `../weights/` for the C++ inference engine.

- `main.py` — downloads `GPT2LMHeadModel` / `GPT2Tokenizer`, dumps every parameter flattened to `../weights/<name>.txt`, saves the tokenizer to `../weights/tokenizer/`.
- Run with `uv sync && uv run main.py` (see root README).
- Output (~1.4 GB) is gitignored; regenerate locally, never commit it.
