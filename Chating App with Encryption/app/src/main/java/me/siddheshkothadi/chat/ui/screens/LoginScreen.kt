package me.siddheshkothadi.chat.ui.screens

import android.util.Log
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.isSystemInDarkTheme
import androidx.compose.foundation.layout.*
import androidx.compose.material3.CircularProgressIndicator
import androidx.compose.material3.OutlinedButton
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.alpha
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavHostController
import com.airbnb.lottie.compose.*
import com.google.android.gms.auth.api.signin.GoogleSignIn
import com.google.android.gms.common.api.ApiException
import com.google.firebase.auth.GoogleAuthProvider
import me.siddheshkothadi.chat.ui.viewmodel.MainViewModel
import me.siddheshkothadi.chat.R

@Composable
fun LoginScreen(
    mainViewModel: MainViewModel
) {
    val context = LocalContext.current
    val lottieCompositionSpec =
        if (isSystemInDarkTheme()) LottieCompositionSpec.RawRes(R.raw.chat_dark) else LottieCompositionSpec.RawRes(
            R.raw.chat_light
        )
    val composition by rememberLottieComposition(lottieCompositionSpec)
    val progress by animateLottieCompositionAsState(
        composition,
        iterations = LottieConstants.IterateForever,
    )

    val isSigningIn by mainViewModel.isSigningIn.collectAsState()

    val launcher =
        rememberLauncherForActivityResult(ActivityResultContracts.StartActivityForResult()) {
            val task = GoogleSignIn.getSignedInAccountFromIntent(it.data)
            try {
                val account = task.getResult(ApiException::class.java)!!
                val credential = GoogleAuthProvider.getCredential(account.idToken!!, null)
                mainViewModel.signWithCredential(credential)
            } catch (e: ApiException) {
                Log.w("Auth", "Google sign in failed", e)
            }
        }

    fun launchGoogleSignIn() {
        launcher.launch(GoogleSignIn.getClient(context, mainViewModel.gso).signInIntent)
    }

    Column(
        modifier = Modifier.fillMaxSize(),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Text(
            "\uD83D\uDD10",
            fontWeight = FontWeight.SemiBold,
            fontSize = 36.sp,
            textAlign = TextAlign.Center
        )
        Text(
            "Chat",
            fontWeight = FontWeight.SemiBold,
            fontSize = 48.sp,
            textAlign = TextAlign.Center
        )

        LottieAnimation(
            composition,
            progress,
            modifier = Modifier
                .height(300.dp)
                .width(300.dp)
        )

        Row(
            modifier = Modifier
                .fillMaxWidth()
                .systemBarsPadding(),
            horizontalArrangement = Arrangement.SpaceEvenly
        ) {
            OutlinedButton(
                onClick = { launchGoogleSignIn() },
                modifier = Modifier.width(300.dp)
            ) {
                Text("Login")
            }
        }

        Row(
            modifier = Modifier
                .fillMaxWidth()
                .padding(vertical = 24.dp),
            horizontalArrangement = Arrangement.Center
        ) {
            CircularProgressIndicator(
                Modifier
                    .width(24.dp)
                    .height(24.dp)
                    .alpha(if(isSigningIn) 1f else 0f)
            )
        }
    }
}