import func

text_to_write = func.get_text()

func.write_empty_file("input.txt", text_to_write)

text = func.read_file("input.txt")

print("Entered text:", "\n", text)

NewText = func.ChangeText(text)

func.write_to_file("output.txt", NewText)

output_text = func.read_file("output.txt")

print("\n", "Changed text:", "\n", output_text)


