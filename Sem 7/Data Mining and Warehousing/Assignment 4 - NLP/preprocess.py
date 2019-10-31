import sys
import nltk
from pathlib2 import Path
from nltk.corpus import stopwords
file1 = Path("input.txt").read_text()
file2 = Path("input2.txt").read_text()
file3 = Path("input3.txt").read_text()
op = Path("output.txt")
import re,string,unicodedata

nltk.download('punkt')
nltk.download('stopwords')

def remove_stopwords(words):
	new_words = []
	for word in words:
		if word not in stopwords.words('english'):
			new_words.append(word)
	return new_words

punctuations = '''!()-[]{};:'"\,<>../?@#$%^&*_~'''
def remove_punctuations(words):
	new_words = []
	for word in words:
		if word not in punctuations:
			new_words.append(word)
	return new_words


def word_stemming(words):
	new_words = []
	for word in words:
		if word.endswith("ing"):
			word = word.strip("ing")
		if word.endswith("ed"):	
			word = word.strip("ed")
		new_words.append(word)
	return new_words


words = file1
words = words.lower()
words = nltk.word_tokenize(words)
words = remove_punctuations(words)
words = remove_stopwords(words)
words = word_stemming(words)

contents = ""
for i in words:
	contents = contents + " " + i


words = file2
words = words.lower()
words = nltk.word_tokenize(words)
words = remove_punctuations(words)
words = remove_stopwords(words)
words = word_stemming(words)
contents = contents + "\n"
for i in words:
	contents = contents + " " + i

words = file3
words = words.lower()
words = nltk.word_tokenize(words)
words = remove_punctuations(words)
words = remove_stopwords(words)
words = word_stemming(words)
contents = contents + "\n"
for i in words:
	contents = contents + " " + i

op.write_text(contents)

