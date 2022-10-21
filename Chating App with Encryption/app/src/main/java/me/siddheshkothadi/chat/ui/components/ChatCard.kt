package me.siddheshkothadi.chat.ui.components

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import coil.compose.AsyncImage
import me.siddheshkothadi.chat.domain.model.User

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun ChatCard(
    user: User,
    onClickAction: () -> Unit,
    navigateToProfile: () -> Unit
) {
    Box(
        Modifier
            .fillMaxWidth()
            .padding(vertical = 8.dp, horizontal = 8.dp)) {
        Surface(
            modifier = Modifier
                .fillMaxWidth().clip(RoundedCornerShape(16)).clickable { onClickAction() },
            tonalElevation = 1.5.dp
        ) {
            Row(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(18.dp),
                verticalAlignment = Alignment.CenterVertically
            ) {
                AsyncImage(
                    model = user.photoUrl,
                    contentDescription = "User Image",
                    modifier = Modifier
                        .width(50.dp)
                        .height(50.dp)
                        .clip(CircleShape).clickable {
                            navigateToProfile()
                        }
                )
                Spacer(modifier = Modifier.width(24.dp))
                Text(user.displayName, modifier = Modifier.weight(1f), fontSize = 20.sp, fontWeight = FontWeight.W500)
            }
        }
    }
}