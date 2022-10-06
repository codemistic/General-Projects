import 'package:flutter/material.dart';

Future<void> showDialogBox(
  BuildContext context,
  String des,
  String title,
) {
  return showDialog(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: Text(
          title,
          style: TextStyle(
            fontWeight: FontWeight.bold,
            color: Colors.blue.shade300,
          ),
        ),
        content: Text(
          des,
        ),
        actions: [
          TextButton(
            onPressed: () {
              Navigator.of(context).pop();
            },
            child: const Text('Back'),
          )
        ],
      );
    },
  );
}
