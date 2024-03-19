# perm

A small utility that finds all permutations of a string


### History

A bit of time after I started programming, I was always bugged down by how a program would find all the permutations (or anagrams) of a word. At first, I thought
it would be simple but I quickly realized it wasn't the case. It took a few years until I decided to actually get to it and I eventually figured out an algorithm.
And better than that, even managed to optimize it (maximally, I think, or almost).


### How it works

Let's take a three-letter word: Rin. First, we cut it in two twice, like so: **R|in**, **Ri|n**. Then, we take the left substring and insert it into every
index in the right substring, which gives us: **Rin**, **iRn**, **inR** and **Rin**, **nRi**.

However, if you know your combinatorics, you know that we need more permutations. This is achieved by finding permutations of the substrings, and using the same
method on them. The permutations are: **R|in**, **R|ni** and **Ri|n**, **iR|n**. Now, inserting the left substring into the right one, we additionally get:
**Rni**, **nRi**, **niR** and **iRn**, **niR**.

In total, we have **Rin**, **iRn**, **inR** and **Rin**, **nRi**, and **Rni**, **nRi**, **niR** and **iRn**, **niR**. Again, if you know your combinatorics (or
if you've been attentive), we have too many permutations: there are duplicates. This is easily (in most languages) fixed by using *sets* instead of arrays (or
lists or vectors or whatever). This is because a set can't have the same object twice.

So in the end, we get **Rin**, **iRn**, **inR**, **nRi**, **Rni** and **niR**. And that's it. For words with more characters, it's the same algorithm, you just
have to do more cuts and iterate more times. However, it is a slightly inefficient algorithm.


### Optimizing the algorithm

What I eventually noticed, was that past half of the word, it only creates duplicates. Which quite drastically improves the performance. However, if you keep
thinking about it, and if the word is long enough, you could also ignore everything past a third of the word. And then past a fourth, and so on. The limit is
the square root of the length. Which quite drastically improves the performance, especially for bigger words.


### What's the license?

It's under the MIT license.


### Can I steal the code?

Yes, you can.


### Can I steal the code and make it closed source?

Yes, you can.


### Can I steal the code and make it closed source and sell it?

Absolutely.


### Can I do whatever I want?

Yes. But don't come complaining to me if something breaks. Not my responsibility. Although I have to say, if you manage to break something **solely** because
of my code... You must be very, very unlucky and potentially not that smart. I'd reconsider my life choices at that point...
