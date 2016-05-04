int is_lowercase(char c) {
  if (c >= 'a' && c <= 'z') /* Checks for lowercase */
    return 1;
  return 0;
}

int is_separator(char c) {
  if (c == ' ' || c == '\t' || c == '\n') /* Checks for separator */
    return 1;
  return 0;
}

char *cap_string(char *s) {
  int c;

  for (c = 0; s[c] != '\0'; c++){
    if (c == 0){
      if(is_lowercase(s[c])) {
        s[c] = s[c] - 32;  /* Capitalizes string */
      }
    }
    else if (is_separator(s[c])) {
      if (is_lowercase(s[c + 1])){ /* Capitalizes string */
        s[c + 1] = s[c + 1] - 32;
      }
    }
  }
  return s;
}
