# ft_ssl_md5

An introduction to cryptographic hashing algorithms

A cryptographic hash function is a special class of hash function that has certain propertiesi which make it suitable for use in cryptography. It is a mathematical algorithm that maps data of arbitrary size to a bit string of a fixed size. It is designed to also be a one-way function, that is, a function which is infeasible to invert. The only way to recreate the input data from an ideal cryptographic hash function’s output is to attempt a brute-force search of possible inputs to see if they produce a match, or use a rainbow table of matched hashes. Bruce Schneier has called one-way hash functions "the workhorses of modern cryptography". The input data is often called the message, and the output (the hash value or hash) is often called the message digest or simply the digest.

The ideal cryptographic hash function has five main properties:

• it is deterministic, so the same message always results in the same hash 
• it is quick to compute the hash value for any given message 
• it is infeasible to generate a message from its digest except by trying all possible messages 
• a small change to a message should change the hash value so extensively that the new hash value appears uncorrelated with the old hash value 
• it is infeasible to find two different messages with the same hash value Cryptographic hash functions have many information-security applications, notably in digital signatures, message authentication codes (MACs), and other forms of authen- tication. They can also be used as ordinary hash functions, to index data in hash tables, for fingerprinting, to detect duplicate data or uniquely identify files, and as checksums to detect accidental data corruption. Indeed, in information-security contexts, crypto- graphic hash values are sometimes called (digital) fingerprints, checksums, or just hash values, even though all these terms stand for more general functions with rather different properties and purposes.

This project will focus specifically on cryptographic hashing algorithms to solidify your understanding of bitwise operations, integer overflow, and one-way functions. A subplot to this project is to emphasize writing clean code that can be efficiently extended.

You must create the md5 and the sha256 commands for your ft_ssl program. You must include the following flags: 
	• -p, echo STDIN to STDOUT and append the checksum to STDOUT 
	• -q, quiet mode 
	• -r, reverse the format of the output. 

For example:

echo "pickle rick" | openssl md5
c5e433c1dbd7ba01e3763a9483e74b04

echo "pickle rick" | md5
c5e433c1dbd7ba01e3763a9483e74b04

echo "pickle rick" | ./ft_ssl md5
c5e433c1dbd7ba01e3763a9483e74b04

echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p
Do not pity the dead, Harry.
2d95365bc44bf0a298e09a3ab7b34d2f

echo "Pity the living." | ./ft_ssl md5 -q -r
e20c3b973f63482a778f3fd1869b7f25

./ft_ssl sha256 -s "wubba lubba dub dub"
SHA256 ("wubba lubba dub dub") = 23a0944d11b5a54f1970492b5265c732044ae824b7d5656acb193e7f0e51e5fa

Useful Saurces: https://en.wikipedia.org/wiki/SHA-2
 https://en.wikipedia.org/wiki/MD5
 https://csrc.nist.gov/csrc/media/publications/fips/180/4/final/documents/fips180-4-draft-aug2014.pdf
 http://www.iusmentis.com/technology/hashfunctions/md5/
