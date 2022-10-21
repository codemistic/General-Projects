package me.siddheshkothadi.chat.ui.screens

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.foundation.text.BasicTextField
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.ArrowBack
import androidx.compose.material.icons.filled.Send
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.alpha
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.SolidColor
import androidx.compose.ui.text.input.ImeAction
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavHostController
import coil.compose.AsyncImage
import me.siddheshkothadi.chat.domain.model.User
import me.siddheshkothadi.chat.ui.components.Messages
import me.siddheshkothadi.chat.ui.viewmodel.MainViewModel

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun ChatScreen(
    navHostController: NavHostController,
    mainViewModel: MainViewModel,
    user: User
) {
    val areMessagesLoading by mainViewModel.areMessagesLoading.collectAsState()
    val currentUserUid = mainViewModel.getCurrentUserUid()
    val key =
        if (currentUserUid < user.uid) "${currentUserUid}__join__${user.uid}" else "${user.uid}__join__${currentUserUid}"

    Scaffold(
        topBar = {
            Surface(tonalElevation = 2.dp) {
                CenterAlignedTopAppBar(
                    title = {
                        Text(
                            text = user.displayName,
                            fontSize = 20.sp,
                            maxLines = 1,
                            overflow = TextOverflow.Ellipsis
                        )
                    },
                    modifier = Modifier.windowInsetsPadding(
                        WindowInsets.statusBars.only(
                            WindowInsetsSides.Top
                        )
                    ),
                    navigationIcon = {
                        IconButton(onClick = {
                            navHostController.popBackStack()
                        }) {
                            Icon(Icons.Default.ArrowBack, null)
                        }
                    },
                    actions = {
                        AsyncImage(
                            model = user.photoUrl,
                            contentDescription = "User Photo",
                            modifier = Modifier
                                .height(30.dp)
                                .width(30.dp)
                                .clip(CircleShape)
                                .clickable {
                                    navHostController.navigate("profile/${user.uid}")
                                }
                        )
                        Spacer(Modifier.width(15.dp))
                    }
                )
            }
        },
    ) {
        val textState by mainViewModel.textState

        Column(Modifier.fillMaxSize()) {
            Messages(
                modifier = Modifier
                    .fillMaxWidth()
                    .weight(1f),
                mainViewModel = mainViewModel,
                fromUid = currentUserUid,
                key = key
            )
            Surface(
                tonalElevation = 2.dp,
                shape = RoundedCornerShape(24.dp),
                modifier = Modifier
                    .navigationBarsPadding()
                    .imePadding()
                    .padding(horizontal = 12.dp, vertical = 8.dp)
            ) {
                Row(
                    verticalAlignment = Alignment.CenterVertically,
                    horizontalArrangement = Arrangement.SpaceBetween
                ) {
                    Spacer(Modifier.width(10.dp))
                    CircularProgressIndicator(
                        modifier = Modifier
                            .height(20.dp)
                            .width(20.dp)
                            .alpha(if (areMessagesLoading) 1f else 0f)
                    )
                    BasicTextField(
                        value = textState,
                        onValueChange = { mainViewModel.setTextState(it) },
                        modifier = Modifier
                            .weight(1f)
                            .padding(horizontal = 12.dp, vertical = 18.dp),
                        keyboardOptions = KeyboardOptions(
                            keyboardType = KeyboardType.Text,
                            imeAction = ImeAction.Default
                        ),
                        maxLines = 3,
                        cursorBrush = SolidColor(LocalContentColor.current),
                        textStyle = LocalTextStyle.current.copy(
                            color = LocalContentColor.current,
                            fontSize = 16.sp
                        )
                    )
                    IconButton(onClick = {
                        mainViewModel.addTextToChat(
                            key = key,
                            text = textState,
                            from = currentUserUid,
                            to = user
                        )
                    }) {
                        Icon(
                            Icons.Default.Send,
                            "Send",
                            tint = if (textState.isBlank()) MaterialTheme.colorScheme.onSurface else MaterialTheme.colorScheme.primary
                        )
                    }
                }
            }
        }
    }
}