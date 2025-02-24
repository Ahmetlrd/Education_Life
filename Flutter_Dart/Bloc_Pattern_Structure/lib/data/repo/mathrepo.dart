class Mathrepo {
  int doSum(String gotNumber1, String gotNumber2) {
    int a = int.parse(gotNumber1);
    int b = int.parse(gotNumber2);
    int sum = a + b;
    return sum;
  }

  int doProduct(String gotNumber1, String gotNumber2) {
    int a = int.parse(gotNumber1);
    int b = int.parse(gotNumber2);
    int product = a * b;
    return product;
  }
}
