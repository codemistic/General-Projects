import 'dart:math';

class CalculatorBrain {
  CalculatorBrain({this.weight, this.height});

  final int height;
  final int weight;
  double _bmi;

  String calculateBMI() {
     _bmi= weight/pow(height/100, 2);
    return _bmi.toStringAsFixed(1);
  }
  String getResult()
  {
    if(_bmi>=25)
      {
        return 'overweight';
      }
    else if(_bmi>18.5)
      {
        return 'normal';
      }
    else
      {
        return 'underweight';
      }
  }


  String getInterpretation()
  {
    if(_bmi>=25)
    {
      return 'You have a higher than a normal body weight, Try to exercise more.';
    }
    else if(_bmi>18.5)
    {
      return 'You have a normal body weight, good job !';
    }
    else
    {
      return 'You have a lower than normal body weight. You need to eat a bit more';
    }
  }


}
