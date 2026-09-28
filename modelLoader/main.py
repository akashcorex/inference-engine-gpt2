from pathlib import Path
from transformers import GPT2LMHeadModel, GPT2Tokenizer

out = Path("../weights")
out.mkdir(parents=True, exist_ok=True)

model = GPT2LMHeadModel.from_pretrained("gpt2")

for name, param in model.named_parameters():
    print(name, tuple(param.shape))
    values = param.detach().numpy().flatten()
    (out / f"{name}.txt").write_text(" ".join(map(str, values)))

tokenizer = GPT2Tokenizer.from_pretrained("gpt2")
tokenizer.save_pretrained(out / "tokenizer")    