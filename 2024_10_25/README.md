# Russ Cox

### "Play Tic-Tac-Toe with Knuth" [[Post](https://research.swtch.com/tictactoe)]

https://onlinebooks.library.upenn.edu/

https://onlinebooks.library.upenn.edu/search.html

### "On Duff's Device and Coroutines"[[Post](https://research.swtch.com/duff)]

Max Krohn:

1- tame preprocessor --> page not found --> https://pdos.lcs.mit.edu/people/ --> Max Krohn --> DuckDuckG0 --> https://startmit-2016.mit.edu/maxwell-krohn/ --> Founder of OkCupid.com

2- DuckDuckG0 --> https://phys.org/news/2015-04-mit-students-world-scientific-journals.html --> https://pdos.csail.mit.edu/archive/scigen/scipher.html --> [mind-blowing](https://pdos.csail.mit.edu/archive/scigen/index.html)


# SCIgen

This Perl script is a core component of the SCIgen project, which generates random, humorous research papers. Let's break down its functionality:

Duplication Functions:

dup_name and file_name add identifiers to file and rule names, marking certain rules as non-duplicates.
Rule Parsing:

The read_rules subroutine reads and interprets the rules from an input file. It handles rule inclusion, duplicate avoidance, and weight assignment for each rule.
Random Rule Selection:

pick_rand randomly picks a rule for generating content, adding unpredictability to the generated paper.
String Expansion:

expand interprets each rule, filling in text based on predefined templates and recursively applying other rules as needed to generate content.
Formatting:

pretty_print adjusts grammar and formats special sections like titles, subsections, and labels for LaTeX compatibility, making output more structured and readable.
SCIgen-specific Functions:

compute_re builds a regex from rule names, identifying patterns and allowing structured expansion.
generate orchestrates the generation process, starting from a main rule and applying expansion and formatting.
This code ultimately enables SCIgen to create plausible-sounding research papers by chaining randomly chosen templates in coherent sequences, making it suitable for demonstrating pseudo-scientific content for comedic purposes. Let me know if you'd like further details on any part!






You said:
how it does that? I mean how it compares to these days where people train large language models?
ChatGPT said:
ChatGPT
SCIgen takes a much simpler, rule-based approach to text generation compared to today’s large language models (LLMs). Here’s how it works in contrast to LLMs:

1. Rule-Based Template System vs. Learned Language Patterns
SCIgen uses predefined templates and a set of rules that specify possible sentence structures and word replacements. Each rule points to potential phrases or sections to include in the generated text. For example, it might use placeholders like <INTRODUCTION> or <METHODS> and fill these with randomly chosen scientific-sounding phrases or sentences.
LLMs like GPT or ChatGPT are trained on vast amounts of text data, allowing them to learn natural language patterns, grammar, and context. Instead of pre-made rules, LLMs generate text by predicting the next word based on the patterns learned during training. They don’t need pre-set templates or specific word choices because they can draw from a diverse and nuanced understanding of language.
2. Randomness in SCIgen vs. Probabilistic Modeling in LLMs
SCIgen uses a random selection mechanism. When generating content, it picks a template or phrase at random from a list of possibilities. This randomness makes the text sound different each time but can lead to incoherence.
LLMs don’t use strict randomness. Instead, they rely on probability distributions learned during training. When they generate text, they choose words or phrases with high relevance probabilities based on the input prompt. This allows them to stay coherent and contextually relevant over longer passages.
3. Output Quality and Coherence
SCIgen generates content that appears scientific only on the surface. Because it relies on fixed templates, it lacks true contextual understanding and often produces humorous but nonsensical results. For instance, it might generate random jargon in place of a real methodology, creating an illusion of coherence without any real meaning.
LLMs aim for genuine coherence and context. They can understand complex prompts, retain context over paragraphs, and adjust their tone, style, and level of detail to match the given prompt. They produce text that appears coherent, relevant, and often indistinguishable from human writing.
4. Adaptability and Use Cases
SCIgen is a niche tool, purpose-built to create parodies of scientific papers. It’s hard to adapt for other use cases, as changing its behavior requires modifying templates and rules.
LLMs are far more adaptable, with applications ranging from customer service to content generation, language translation, coding assistance, and more. They can understand and respond to a wide variety of prompts, making them versatile across domains.
5. Computational Complexity
SCIgen is lightweight and computationally simple. It can generate text on standard hardware without much processing power since it relies on simple template expansions and random selections.
LLMs are computationally intensive, requiring powerful hardware and vast datasets to train. Inference (text generation after training) also demands significant resources, especially for larger models. This complexity allows LLMs to capture the subtle nuances of human language but comes at a much higher cost.
Summary
SCIgen’s rule-based approach is highly structured and static, making it good for simple tasks like generating nonsensical research papers with a humorous spin. In contrast, LLMs are dynamic, adaptable, and capable of understanding and generating nuanced, coherent, and contextually relevant text across many domains due to the vast amounts of data they are trained on.
