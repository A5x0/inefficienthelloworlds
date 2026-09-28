function preliminary_request(message,    request) {
    request["text"] = message
    request["status"] = "pending"
    return request["status"]
}

function request_review(status) {
    if (status == "pending")
        return "reviewed"
    return "denied"
}

function first_review(status) {
    if (status == "reviewed")
        return "passed"
    return "rejected"
}

function second_review(status) {
    if (status == "passed")
        return "passed"
    return "rejected"
}

function third_review(status) {
    if (status == "passed")
        return "passed"
    return "rejected"
}

function final_review(status) {
    if (status == "passed")
        return "completed"
    return "failed"
}

function higher_approval(status) {
    if (status == "completed")
        return "authorized"
    return "rejected"
}

function print_final_message(message, status) {
    if (status == "authorized")
        print message
    else
        print "rejected"
}
BEGIN {message = "Hello, World!"

    status = preliminary_request(message)
    status = first_review(status)
    status = second_review(status)
    status = third_review(status)
    status = final_review(status)
    status = higher_approval(status)

    print_final_message(message, status)
}
