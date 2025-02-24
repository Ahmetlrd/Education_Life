import 'dart:ffi';

import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:flutter_blocpattern/data/repo/mathrepo.dart';

class HomepageCubit extends Cubit<int> {
  HomepageCubit() : super(0);
  var mrepo = Mathrepo();
  void doSum(String gotNumber1, String gotNumber2) {
    emit(mrepo.doSum(gotNumber1, gotNumber2));
  }

  void doProduct(String gotNumber1, String gotNumber2) {
    emit(mrepo.doProduct(gotNumber1, gotNumber2));
  }
}
