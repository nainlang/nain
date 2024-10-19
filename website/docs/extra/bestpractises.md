---
sidebar_position: 1
---

# Best Practises

Here are some best practises that you should follow when writing nain programs.

## Use `let` instead of `var`

It might sound stupid to have 2 keywords that do the exact same thing, but it's important to know that `let` is a lot safer than `var`.

`var` variables can be changed by external code, which can be dangerous.

`let` variables can't be changed by external code, which is safer. They only exist on the Virtual Machine, and are not accessible from outside the program.

## Naming conventions

---

| Name                   | Description        |
| ---------------------- | ------------------ |
| `camelCase`            | Used for variables |
| `snake_vase`           | Used for functions |
| `PascalCase`           | Used for classes   |
| `SCREAMING_SNAKE_CASE` | Used for constants |
| `kebab-case`           | Used for enums     |

---

## Use different files for different parts of the program

It's a good idea to split your program into different files, depending on what they do.

For example, you might have a `src` folder with a `main.nain`, and instide a `utils` folder
with the `utils.nain` and `constants.nain` files.

This way, you can easily import the `utils` functions and constants from the `main` file.

```nain
with file utils

fn main() {
    utils.get_some_data()
}
```

:::tip
Use the `with file` keyword to import files
:::

## Don't invent new paradigms

Don't invent new paradigms, use the ones that already exist.
That way, everyone can understand your code.

The 3 main paradigms are:

-   Functional Programming
-   Object Oriented Programming
-   Imperative Programming

If you're not familiar with any of these paradigms, you should learn them.
There are a ton of resources online, and you can even find courses on YouTube.

## Use the `studio` library

The `studio` library is a collection of functions that are used to interact with i/o, and to let functions access the memory outside of the program.

You will need to use this at some point in your program.

```nain
with lib studio
```

## Don't try to guess the exact usage of a library

If you are using a library, don't try to guess the exact usage of it.

Instead, read the documentation and try to understand what the library is doing.

If there isn't any documentation, you can always ask the author of the library.

I hope this helps you write better nain programs! 😊
