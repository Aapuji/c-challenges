#include "charstream.h"

charstream::charstream() {
  stream = {};
}

charstream::charstream(std::string str) {
  stream = {};  
  
  for (char c : str)
    stream.push(c);
}

charstream::charstream(const char *s) {
  stream = {};

  for (char c = *s; c; c = *++s) {
    stream.push(c);
  }
}

void charstream::push(char c) {
  stream.push(c);
}

void charstream::push(std::string str) {
  for (char c : str) 
    stream.push(c);
}

charstream charstream::operator[](int i) {
  std::string out = "";

  for (; i >= 0 && !stream.empty(); i--)
    out += this->next();

  charstream c(out);
  return c;
}

char charstream::front() {
  return stream.front();
}

char charstream::next() {
  char c = stream.front();
  stream.pop();
  return c;
}

std::string charstream::flush() {
  std::string out = "";

  while (!stream.empty())
    out += this->next();

  return out;
}

void charstream::clear() {
  while (!stream.empty()) 
    stream.pop();
}

charstream::operator std::string() {
  std::string str = "";

  while (!stream.empty())
    str += this->next();

  this->push(str);
  return str;
}

charstream charstream::operator=(std::string str) {
  charstream c(str);
  return c;
}
