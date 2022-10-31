function modal() {
    $("#modal-trigger").animatedModal({
        modalTarget:'js-modal',
        animatedIn:'lightSpeedIn',
        animatedOut:'bounceOutDown',
        color:'#3498db',
        // Callbacks
        beforeOpen: function() {
            console.log("The animation was called");
        },
        afterOpen: function() {
            console.log("The animation is completed");
        },
        beforeClose: function() {
            console.log("The animation was called");
        },
        afterClose: function() {
            console.log("The animation is completed");
        }
    });
}

function main() {
    $('.movies__item').hover(function() {
        $(this).find('.movies__item-image').css({"filter": "brightness(20%)"});
        $(this).find('.movies__item-star').toggleClass('hide');
        $(this).find('.movies__item-rating').toggleClass('hide');
        $(this).find('.movies__item-expander').toggleClass('hide');
        $(this).find('.movies__item-delete-button').toggleClass('hide');
    }, function() {
        $(this).find('.movies__item-image').css({"filter": "brightness(100%)"});
        $(this).find('.movies__item-star').toggleClass('hide');
        $(this).find('.movies__item-rating').toggleClass('hide');
        $(this).find('.movies__item-expander').toggleClass('hide');
        $(this).find('.movies__item-delete-button').toggleClass('hide');
    });

    modal();
}

$(document).ready(main());

