import styles from './header.module.scss';
import classNames from 'classnames';
import headerIcon from '../../assets/placeholder.png';

export interface HeaderProps {
    className?: string;
}

/**
 * This component was created using Codux's Default new component template.
 * To create custom component templates, see https://help.codux.com/kb/en/article/kb16522
 */
export const Header = ({ className }: HeaderProps) => {
    return (
        <div className={classNames(styles.root, className)}>
            <header className={styles.header}>
                <div className={styles['header-title']}>
                    <h1>DomusOrdo</h1>
                    <h2>Domus in ordine, animus in ordine</h2>
                </div>
                <img src={headerIcon} alt="holap" className={styles['header-icon']} />
            </header>
        </div>
    );
};
