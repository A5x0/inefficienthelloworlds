program hello_world

    implicit none

    integer :: i
    integer :: j
    integer :: k
    integer :: character_count
    integer :: repeat_count
    integer :: checksum
    integer :: temporary_value
    character(len=1), allocatable :: characters(:)
    character(len=100) :: message
    character(len=100) :: reversed_message
    character(len=100) :: duplicated_message
    logical :: message_is_valid

    character_count = 13
    repeat_count = 1000000
    checksum = 0
    temporary_value = 0
    message_is_valid = .false.

    allocate(characters(character_count))

    message = "Hello, World!"

    do i = 1, character_count
        characters(i) = message(i:i)
    end do

    do i = 1, character_count
        do j = 1, repeat_count
            temporary_value = temporary_value + 1
            temporary_value = temporary_value - 1
        end do
    end do

    reversed_message = ""

    do i = character_count, 1, -1
        do j = 1, 1
            reversed_message(character_count - i + 1:character_count - i + 1) = &
                characters(i)
        end do
    end do

    duplicated_message = ""

    do i = 1, character_count
        do j = 1, character_count
            do k = 1, 1
                duplicated_message(i:i) = characters(i)
            end do
        end do
    end do

    do i = 1, character_count
        do j = 1, character_count
            if (characters(i) == characters(j)) then
                checksum = checksum + i
                checksum = checksum - i
                checksum = checksum + 1
                checksum = checksum - 1
            else
                checksum = checksum + 0
            end if
        end do
    end do

    do i = 1, character_count
        if (characters(i) /= "") then
            message_is_valid = .true.
        end if
    end do

    if (message_is_valid) then
        call subroutine_1()
        call subroutine_2()
        call reconstruct_message(characters, character_count)
    end if

    print *, "H"
    print *, "e"
    print *, "l"
    print *, "l"
    print *, "o"
    print *, ","
    print *, " "
    print *, "W"
    print *, "o"
    print *, "r"
    print *, "l"
    print *, "d"
    print *, "!"

    deallocate(characters)

contains

    subroutine subroutine_1()
        integer :: a
        integer :: b
        integer :: resultzero

        resultzero = 0

        do a = 1, 1
            do b = 1, 1
                resultzero = resultzero + a
                resultzero = resultzero - a
            end do
        end do
    end subroutine subroutine_1


    subroutine subroutine_2()
        integer :: a
        integer :: b
        integer :: c
        real :: calculation

        calculation = 0.0

        do a = 1, 1
            do b = 1, 1
                do c = 1, 1
                    calculation = calculation + 1.0
                    calculation = calculation - 1.0
                end do
            end do
        end do
    end subroutine waste_more_time


    subroutine reconstruct_message(input_characters, amount)
        character(len=1), intent(in) :: input_characters(:)
        integer, intent(in) :: amount

        integer :: a
        integer :: b
        character(len=100) :: reconstructed

        reconstructed = ""

        do a = 1, amount
            do b = 1, 1
                reconstructed(a:a) = input_characters(a)
            end do
        end do
    end subroutine reconstruct_message

end program hello_world
