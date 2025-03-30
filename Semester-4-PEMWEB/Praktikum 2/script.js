let humanScore = 0;
let computerScore = 0;
let totalPlayed = 0;

function getComputerChoice() {
    randomValue = Math.floor(Math.random() * 3);
    switch (randomValue) {
        case 0:
            return "batu";
        case 1:
            return "gunting";
        default:
            return "kertas";
    }
}

function playGame(humanChoice) {
    totalPlayed++;
    let humanSelection = humanChoice;
    let computerSelection = getComputerChoice();

    document.getElementById(
        "choice"
    ).innerHTML = `Kamu : ${humanSelection.toUpperCase()} VS Musuh : ${computerSelection.toUpperCase()}`;

    playRound(humanSelection, computerSelection);

    document.getElementById(
        "skor"
    ).innerHTML = `Skor kamu : ${humanScore} || Skor musuh : ${computerScore}`;

    document.getElementById(
        "total-played"
    ).innerHTML = `Total main : ${totalPlayed}`;
}

function playRound(humanSelection, computerSelection) {
    if (humanSelection == "batu") {
        if (computerSelection == "kertas") {
            defeatMessage();
            computerScore++;
        } else if (computerSelection == "batu") {
            drawMessage();
        } else {
            winMessage();
            humanScore++;
        }
    } else if (humanSelection == "kertas") {
        if (computerSelection == "kertas") {
            drawMessage();
        } else if (computerSelection == "batu") {
            winMessage();
            humanScore++;
        } else {
            defeatMessage();
            computerScore++;
        }
    } else if (humanSelection == "gunting") {
        if (computerSelection == "gunting") {
            drawMessage();
        } else if (computerSelection == "kertas") {
            winMessage();
            humanScore++;
        } else {
            defeatMessage();
            computerScore++;
        }
    }
}

function defeatMessage() {
    document.getElementById("result-text").innerHTML = `Kamu kalah oakwoawo`;
}
function winMessage() {
    document.getElementById("result-text").innerHTML = `Kamu menang anjay`;
}
function drawMessage() {
    document.getElementById("result-text").innerHTML = `Yah seri`;
}
