<?php

if ($this->noMatch) {
    echo "Email/password do not match.";
} else {
    echo "Welcome back, " . $this->name . "!";
}
