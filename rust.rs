use std::{
    sync::mpsc,
    thread,
    time::Duration,
};

fn main() {
    let source = vec![
        'H', 'e', 'l', 'l', 'o', ',', ' ',
        'W', 'o', 'r', 'l', 'd', '!',
    ];

    let (sender, receiver) = mpsc::channel();

    let mut handles = Vec::new();

    for character in source {
        let sender = sender.clone();

        handles.push(thread::spawn(move || {
            let character = vec![character]
                .into_iter()
                .collect::<Vec<_>>()
                .into_iter()
                .map(|c| c.to_string())
                .collect::<String>();

            thread::sleep(Duration::from_millis(1));

            sender.send(character).unwrap();
        }));
    }

    drop(sender);

    let mut characters = receiver
        .into_iter()
        .collect::<Vec<_>>();

    let expected = "Hello, World!"
        .chars()
        .enumerate()
        .map(|(index, character)| (index, character.to_string()))
        .collect::<Vec<_>>();

    characters.sort();

    let mut output = String::new();

    for (_, character) in expected {
        if characters.contains(&character) {
            output.push_str(&character);
        }
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("{}", output);
}
